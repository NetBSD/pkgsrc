# $NetBSD: Makefile,v 1.15 2002/01/16 14:59:38 tron Exp $

DISTNAME=	xchat-1.8.7
CATEGORIES=	chat x11 gnome
MASTER_SITES=	${HOMEPAGE}files/source/1.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/
COMMENT=	X11 (X Window System) IRC client, using the GTK+ toolkit

DEPENDS+=	python>=2.0:../../lang/python

USE_GMAKE=	YES
USE_PERL5=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	ac_cv_lib_intl_bindtextdomain='yes'
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-panel

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# SSL support
.if defined(XCHAT_USE_SSL) && ${XCHAT_USE_SSL} == "YES"
.include "../../security/openssl/buildlink.mk"
CONFIGURE_ARGS+=	--enable-openssl=${BUILDLINK_DIR}
.endif

# Prevent invokation of "auto*" which caused build failures due to insufficient
# arguments and environment.
pre-configure:
	@cd ${WRKSRC} && \
	${RM} -f po/zh_TW.Big5.po && \
	${TOUCH} aclocal.m4 stamp-h.in configure && \
	${FIND} . -name Makefile.in | ${XARGS} ${TOUCH}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
