# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 17:56:29 rh Exp $
#

DISTNAME=		eel-1.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/eel/}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		Eazel Extenstions Library

DEPENDS+=		librsvg-*:../../graphics/librsvg
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
USE_PERL5=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/bsd.pkg.mk"
