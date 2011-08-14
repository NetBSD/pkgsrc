# $NetBSD: Makefile,v 1.5 2011/08/14 14:52:52 obache Exp $

DISTNAME=	smbldap-tools-${VERS}
PKGREVISION=	1
CATEGORIES=	sysutils net databases
MASTER_SITES=	http://download.gna.org/smbldap-tools/sources/${VERS}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gna.org/projects/smbldap-tools/
COMMENT=	Set of ldap administration scripts for samba

PKG_DESTDIR_SUPPORT=	user-destdir

VERS=		0.9.6

#DEPENDS+=	samba>=3.0.22:../../net/samba33
DEPENDS+=	p5-perl-ldap>=0.33:../../databases/p5-perl-ldap
DEPENDS+=	p5-Crypt-SmbHash>=0.12:../../security/p5-Crypt-SmbHash
DEPENDS+=	p5-Digest-SHA1>=2.11:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Unicode-MapUTF8-[0-9]*:../../converters/p5-Unicode-MapUTF8

NO_BUILD=	yes
USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}/smbldap-tools-${VERS}

SMBLDAP_CONF=	smbldap.conf smbldap_bind.conf
SMBLDAP_DOCS=	doc/smbldap-tools.html doc/smbldap-tools.pdf
SMBLDAP_EG=	doc/slapd.conf doc/smb.conf
SMBLDAP_LIBS=	smbldap_tools.pm
SMBLDAP_PASSWD=	smbldap-passwd
SMBLDAP_TOOLS=	smbldap-groupadd smbldap-groupdel smbldap-grouplist \
		smbldap-groupmod smbldap-groupshow  \
		smbldap-useradd smbldap-userdel smbldap-userinfo \
		smbldap-usermod smbldap-usershow
SMBLDAP_UTILS=	configure.pl smbldap-populate \
		doc/migration_scripts/smbldap-migrate-pwdump-accounts \
		doc/migration_scripts/smbldap-migrate-pwdump-groups \
		doc/migration_scripts/smbldap-migrate-unix-accounts \
		doc/migration_scripts/smbldap-migrate-unix-groups

REPLACE_PERL=	${SMBLDAP_LIBS} ${SMBLDAP_PASSWD} ${SMBLDAP_TOOLS} \
		${SMBLDAP_UTILS}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-install
SUBST_FILES.path=	configure.pl doc/slapd.conf doc/smb.conf
SUBST_FILES.path+=	smbldap_tools.pm smbldap.conf
SUBST_SED.path=		-e "s,@PREFIX@,${PREFIX},g"
SUBST_SED.path+=	-e "s,@OPENLDAP_VARDIR@,${OPENLDAP_VARDIR},g"
SUBST_SED.path+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g"
SUBST_SED.path+=	-e "s,@SAMBA_PIDDIR@,${SAMBA_PIDDIR},g"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	configure.pl
SUBST_SED.conf+=	-e '/^\# \\.Source: /s/\\\$$//g'
SUBST_SED.conf+=	-e '/^\# Source: /s/\$$//g'
SUBST_SED.conf+=	-e '/^\# \\.Id: /s/\\\$$//g'
SUBST_SED.conf+=	-e '/^\# Id: /s/\$$//g'

EGDIR=			share/examples/smbldap-tools

CONF_FILES+=		${EGDIR}/smbldap.conf ${PKG_SYSCONFDIR}/smbldap.conf
CONF_FILES_PERMS+=	${EGDIR}/smbldap_bind.conf \
			${PKG_SYSCONFDIR}/smbldap_bind.conf \
			${BINOWN} ${BINGRP} 0600

BUILD_DEFS=		VARBASE
INSTALLATION_DIRS=	bin ${PERL5_INSTALLVENDORLIB} \
			sbin/smbldap-tools share/doc/smbldap-tools ${EGDIR}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	smbldap-tools
OPENLDAP_VARDIR?=	${VARBASE}/openldap
SAMBA_PIDDIR?=		${VARBASE}/run

do-install:
.for f in ${SMBLDAP_LIBS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
.endfor
.for f in ${SMBLDAP_PASSWD}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in ${SMBLDAP_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/sbin
.endfor
.for f in ${SMBLDAP_UTILS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/sbin/smbldap-tools
.endfor
.for f in ${SMBLDAP_CONF} ${SMBLDAP_EG}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/examples/smbldap-tools
.endfor
.for f in ${SMBLDAP_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/smbldap-tools
.endfor

.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
