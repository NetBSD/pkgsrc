# $NetBSD: Makefile,v 1.9 2001/08/17 19:04:58 fredb Exp $

DISTNAME=	xchat-1.8.2
CATEGORIES=	chat x11 gnome
MASTER_SITES=	${HOMEPAGE}files/source/1.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/
COMMENT=	X11 (X Window System) IRC client, using the GTK+ toolkit

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	python>=2.0:../../lang/python

USE_GMAKE=	YES
USE_PERL5=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	ac_cv_lib_intl_bindtextdomain='yes'
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
