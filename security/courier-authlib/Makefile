# $NetBSD: Makefile,v 1.68 2024/02/21 03:46:06 schmonz Exp $

.include "Makefile.common"

DISTNAME=	courier-authlib-0.72.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier Authentication Library
HOMEPAGE=	https://www.courier-mta.org/authlib/
LICENSE=	gnu-gpl-v3

CONFLICTS+=	courier-auth-[0-9]*
CONFLICTS+=	courier-authldap-[0-9]*
CONFLICTS+=	courier-authmysql-[0-9]*
CONFLICTS+=	courier-authpgsql-[0-9]*

USE_LIBTOOL=		yes
PKG_SYSCONFSUBDIR=	authlib

REPLACE_PERL=		samplepipe.pl sysconftool

USE_LANGUAGES=		c c++
USE_TOOLS+=		cat:run gmake perl:run pkg-config
CONFIGURE_ENV+=		CAT=${TOOLS_CAT}		# makedat

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-stdheaderdir

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--enable-new-dtags
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--enable-new-dtags

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

.include "../../mk/bsd.prefs.mk"

AUTHDAEMONVAR?=		${VARBASE}/authdaemon
CONFIGURE_ARGS+=	--with-authdaemonvar=${AUTHDAEMONVAR:Q}
OWN_DIRS_PERMS=		${AUTHDAEMONVAR} ${COURIER_USER} ${COURIER_GROUP} 0750
FILES_SUBST+=		AUTHDAEMONVAR=${AUTHDAEMONVAR:Q}

# Expect is used to change the password from within the courier webmail
# application (sqwebmail).  Assume that it's installed in the same prefix
# as courier-authlib.
#
CONFIGURE_ENV+=		EXPECT=${PREFIX}/bin/expect
CHECK_INTERPRETER_SKIP=	libexec/courier-authlib/authsystem.passwd

AUTHLIBDIR=		lib/courier-authlib
AUTHLIBEXECDIR=		libexec/courier-authlib
AUTHEXAMPLEDIR=		share/examples/courier-authlib
AUTHDOCDIR=		share/doc/courier-authlib
FILES_SUBST+=		AUTHLIBEXECDIR=${AUTHLIBEXECDIR}
FILES_SUBST+=		AUTHEXAMPLEDIR=${AUTHEXAMPLEDIR}

EGDIR=			${PREFIX}/${AUTHEXAMPLEDIR}
DOCDIR=			${PREFIX}/${AUTHDOCDIR}
RCD_SCRIPTS=		authdaemond
GEN_FILES=		authdaemonrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
AUTHLIB_PLIST=		${AUTHEXAMPLEDIR}/authdaemonrc.dist

# Install the example config files into ${EGDIR}.
INSTALL_AM_MAKEFLAGS=	authdaemonrc=${EGDIR}/authdaemonrc		\
			authldaprc=${EGDIR}/authldaprc			\
			authmysqlrc=${EGDIR}/authmysqlrc		\
			authpgsqlrc=${EGDIR}/authpgsqlrc
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

.include "options.mk"

.for file in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${file}.dist ${PKG_SYSCONFDIR}/${file} \
			${COURIER_USER} ${COURIER_GROUP} 0660
.endfor

.for file in ${AUTHLIB_PLIST}
GENERATE_PLIST+=	${TEST} -f ${DESTDIR}${PREFIX}/${file} &&	\
			${ECHO} "${file}";
.endfor
GENERATE_PLIST+=	${TRUE};

INSTALLATION_DIRS+=	bin sbin ${EGDIR} ${DOCDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.authdebug.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README_authlib.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authdaemonrc ${DESTDIR}/${EGDIR}/authdaemonrc.dist

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mail/courier-unicode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
