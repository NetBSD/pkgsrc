# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:19 jlam Exp $

DISTNAME=	rosegarden-2.1pl2
PKGNAME=	rosegarden-2.1p2
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bath.ac.uk/~masjpf/rose.html
COMMENT=	notation editor & midi sequencer

CPPFLAGS+=	-I${PREFIX}/include

GNU_CONFIGURE=	YES
USE_GMAKE=	yes
MAKE_ENV+=	GCC=yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"

#eof
