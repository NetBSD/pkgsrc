# $NetBSD: Makefile,v 1.2 2001/08/14 08:11:11 rh Exp $
#

DISTNAME=		eel-1.0.1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/eel/}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		Eazel Extenstions Library

DEPENDS+=		librsvg>=1.0.1:../../graphics/librsvg
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
