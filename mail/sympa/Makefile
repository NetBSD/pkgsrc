# $NetBSD: Makefile,v 1.11 2004/10/03 00:12:55 tv Exp $
#

DISTNAME=	sympa-4.1.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.sympa.org/
COMMENT=	Mailing list manager

DEPENDS+=	p5-Archive-Zip>=1.05:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-MIME-Base64>=1.0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-DBD-Sybase>=0.90:../../databases/p5-DBD-Sybase
DEPENDS+=	p5-DBI>=1.06:../../databases/p5-DBI
DEPENDS+=	p5-perl-ldap>=0.27:../../databases/p5-perl-ldap
DEPENDS+=	p5-File-Spec>=0.8:../../devel/p5-File-Spec
DEPENDS+=	p5-IO-stringy>=1.0:../../devel/p5-IO-stringy
DEPENDS+=	mhonarc-[0-9]*:../../mail/mhonarc
DEPENDS+=	p5-MIME-tools>=5.209:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.51:../../mail/p5-MailTools
DEPENDS+=	p5-Net>=1.0:../../net/p5-Net
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-Crypt-CipherSaber>=0.50:../../security/p5-Crypt-CipherSaber
DEPENDS+=	p5-Digest-MD5>=2.00:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-Socket-SSL>=0.90:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Net-SSLeay>=1.16:../../security/p5-Net-SSLeay
DEPENDS+=	p5-CGI>=2.52:../../www/p5-CGI
DEPENDS+=	p5-FCGI>=0.67:../../www/p5-FCGI
DEPENDS+=	p5-libwww>=1.09:../../www/p5-libwww
DEPENDS.SunOS+=	p5-DB_File>=1.75:../../databases/p5-DB_File

OPSYSVARS+=	DEPENDS

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cgidir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-iconsdir=${SYMPA_PREFIX}/httpd/icons
CONFIGURE_ARGS+=	--with-bindir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-sbindir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-libexecdir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-libdir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-datadir=${SYMPA_BIN}/etc
CONFIGURE_ARGS+=	--with-expldir=${SYMPA_VARBASE}/expl
CONFIGURE_ARGS+=	--with-mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--with-lockdir=${SYMPA_VARBASE}/lock
CONFIGURE_ARGS+=	--with-piddir=${SYMPA_VARBASE}/run
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}/sympa
CONFIGURE_ARGS+=	--with-nlsdir=${SYMPA_PREFIX}/nls
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/sympa
CONFIGURE_ARGS+=	--with-scriptdir=${SYMPA_BIN}
CONFIGURE_ARGS+=	--with-sampledir=${PREFIX}/share/examples/sympa
CONFIGURE_ARGS+=	--with-spooldir=${SYMPA_SPOOL}
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-mhonarc=${MHONARC_PREFIX}/bin/mhonarc
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}/bin/openssl
CONFIGURE_ARGS+=	--with-user=${SYMPA_USER}
CONFIGURE_ARGS+=	--with-group=${SYMPA_GROUP}

MHONARC_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		MHONARC_PREFIX=mhonarc

PERL5_REQD+=	5.005

PKG_OPTIONS_VAR=	PKG_OPTIONS.sympa
PKG_SUPPORTED_OPTIONS=	mysql pgsql
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.0407:../../databases/p5-DBD-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=0.90:../../databases/p5-DBD-postgresql
.endif

SYMPA_USER?=	sympa
SYMPA_GROUP?=	sympa
SYMPA_VARBASE?=	${VARBASE}/sympa

BUILD_DEFS+=	SYMPA_USER SYMPA_GROUP SYMPA_VARBASE

SYMPA_PREFIX=	${PREFIX}/sympa
SYMPA_SPOOL=	${SYMPA_VARBASE}/spool
SYMPA_BIN=	${SYMPA_PREFIX}/bin

PKG_GROUPS=	${SYMPA_GROUP}
PKG_USERS=	${SYMPA_USER}:${SYMPA_GROUP}::Sympa\\ user:${SYMPA_VARBASE}

.for d in sympa sympa/create_list_templates sympa/general_task_models \
	sympa/scenari sympa/task_models sympa/templates sympa/wws_templates
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${d} ${SYMPA_USER} ${SYMPA_GROUP} 755
.endfor
OWN_DIRS_PERMS+=	${SYMPA_VARBASE} ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/expl ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/lock ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/run ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL} ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/msg ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/digest ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/moderation ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/expire ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/auth ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/outgoing ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/task ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/tmp ${SYMPA_USER} ${SYMPA_GROUP} 770

SPECIAL_PERMS+=		${SYMPA_BIN}/aliaswrapper ${ROOT_USER} ${SYMPA_GROUP} 4750
SPECIAL_PERMS+=		${SYMPA_BIN}/bouncequeue ${SYMPA_USER} ${SYMPA_GROUP} 4755
SPECIAL_PERMS+=		${SYMPA_BIN}/queue ${SYMPA_USER} ${SYMPA_GROUP} 4755
SPECIAL_PERMS+=		${SYMPA_BIN}/virtualwrapper ${ROOT_USER} ${SYMPA_GROUP} 4750

# Which pkgsrc platforms support set-uid scripts?
#SPECIAL_PERMS+=	${SYMPA_BIN}/sympa_soap_server.fcgi ${SYMPA_USER} ${SYMPA_GROUP} 6755
#SPECIAL_PERMS+=	${SYMPA_BIN}/wwsympa.fcgi ${SYMPA_USER} ${SYMPA_GROUP} 6755

MESSAGE_SUBST+=	SYMPA_BIN=${SYMPA_BIN}

INSTALLATION_DIRS+=	share/doc/sympa

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${OPSYS} == "NetBSD"
	: We do not support set-uid scripts...
	${CHMOD} ug-s ${SYMPA_BIN}/sympa_soap_server.fcgi
	${CHMOD} ug-s ${SYMPA_BIN}/wwsympa.fcgi
.endif
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/sympa/NEWS

.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
