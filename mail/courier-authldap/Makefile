# $NetBSD: Makefile,v 1.1.1.1 2002/01/22 22:02:36 jlam Exp $

PKGNAME=	courier-authldap-${BASE_VERS}
PKGREVISION?=	# empty
COMMENT=	Courier LDAP authentication module

CONFLICTS=	courier-imap-ldap-[0-9]*

PERL5_REQD=	5.6.0
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=	courier-auth>=${BASE_VERS}:../../mail/courier-auth

USE_BUILDLINK_ONLY=	yes
REPLACE_PERL=           sysconftool

.include "../../mail/courier-auth/Makefile.common"

WRKSRC_FILES=		config.guess config.sub configure		\
			install-sh mkinstalldirs
WRKSRC_FILES+=		dbobj.h.in dbobj.config.in sysconftool
WRKSRC_SUBDIRS=		afx bdbobj gdbmobj numlib soxwrap md5 sha1	\
                        libhmac random128 unicode rfc822 rfc1035	\
			rfc2045 liblock
WRKSRC_SUBDIRS+=	makedat userdb authlib

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

CONFIGURE_ARGS+=	--with-authldap

SYSCONFTOOL=		${PREFIX}/sbin/authdaemon.sysconftool
GEN_FILES=		authldaprc
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

DISTINFO_FILE=		${.CURDIR}/../../mail/courier-auth/distinfo
PATCHDIR=		${.CURDIR}/../../mail/courier-auth/patches
INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL

FILES_SUBST+=		SYSCONFTOOL=${SYSCONFTOOL:Q}
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

pre-configure: configure-init

do-build:
.for DIR in ${WRKSRC_SUBDIRS}
	@cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.ldap ${AUTHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldap.schema ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldaprc ${EGDIR}/authldaprc.dist

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
