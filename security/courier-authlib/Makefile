# $NetBSD: Makefile,v 1.9 2005/05/13 03:26:44 jlam Exp $

.include "Makefile.common"

DISTNAME=	courier-authlib-0.55
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Courier Authentication Library
HOMEPAGE=	http://www.courier-mta.org/authlib/

CONFLICTS+=	courier-auth-[0-9]*
CONFLICTS+=	courier-authldap-[0-9]*
CONFLICTS+=	courier-authmysql-[0-9]*
CONFLICTS+=	courier-authpgsql-[0-9]*

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PKG_SYSCONFSUBDIR=	authlib

USE_PERL5=		run
REPLACE_PERL=		sysconftool

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-stdheaderdir

AUTHDAEMONVAR?=		${VARBASE}/authdaemon
CONFIGURE_ARGS+=	--with-authdaemonvar=${AUTHDAEMONVAR}
OWN_DIRS_PERMS=		${AUTHDAEMONVAR} ${COURIER_USER} ${COURIER_GROUP} 0750
FILES_SUBST+=		AUTHDAEMONVAR=${AUTHDAEMONVAR}

# Expect is used to change the password from within the courier webmail
# application (sqwebmail).
#
CONFIGURE_ENV+=		EXPECT="${LOCALBASE}/bin/expect"

AUTHLIBDIR=		lib/courier-authlib
AUTHLIBEXECDIR=		libexec/courier-authlib
AUTHEXAMPLEDIR=		share/examples/courier-authlib
AUTHDOCDIR=		share/doc/courier-authlib
FILES_SUBST+=		AUTHLIBEXECDIR=${AUTHLIBEXECDIR}
FILES_SUBST+=		AUTHEXAMPLEDIR=${AUTHEXAMPLEDIR}

PKG_SYSCONFSUBDIR?=	courier

EGDIR=			${PREFIX}/${AUTHEXAMPLEDIR}
DOCDIR=			${PREFIX}/${AUTHDOCDIR}
RCD_SCRIPTS=		authdaemond
GEN_FILES=		authdaemonrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
AUTHLIB_PLIST=		${AUTHEXAMPLEDIR}/authdaemonrc.dist

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

# Install the example config files into ${EGDIR}.
INSTALL_AM_MAKEFLAGS=	authdaemonrc=${EGDIR}/authdaemonrc		\
			authldaprc=${EGDIR}/authldaprc			\
			authmysqlrc=${EGDIR}/authmysqlrc		\
			authpgsqlrc=${EGDIR}/authpgsqlrc
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

POST_INSTALL_TARGETS=	post-install-common

.include "options.mk"
.include "../../devel/libltdl/buildlink3.mk"

.for _file_ in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${_file_}.dist ${PKG_SYSCONFDIR}/${_file_} \
			${COURIER_USER} ${COURIER_GROUP} 0660
.endfor

.for _file_ in ${AUTHLIB_PLIST}
GENERATE_PLIST+=	${TEST} -f ${PREFIX}/${_file_} && ${ECHO} "${_file_}";
.endfor
.if !empty(AUTHLIB_PLIST:M${AUTHEXAMPLEDIR}/*)
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHEXAMPLEDIR}";
.endif
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHDOCDIR}";
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHLIBEXECDIR}";
GENERATE_PLIST+=	${ECHO} "@dirrm ${AUTHLIBDIR}";

INSTALLATION_DIRS=	bin sbin

post-install: ${POST_INSTALL_TARGETS}

post-install-common:
	${INSTALL_SCRIPT} ${WRKSRC}/makedat/makedat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authldap.schema ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.authdebug.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README_authlib.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
