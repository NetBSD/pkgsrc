# $NetBSD: Makefile,v 1.1.1.1 2001/05/31 16:40:56 agc Exp $

DISTNAME=	rosegarden-2.1pl2
DISTNAME=	rosegarden-2.1p2
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bath.ac.uk/~masjpf/rose.html
COMMENT=	notation editor & midi sequencer

CONFIGURE_ENV+=	CPPFLAGS=-I${PREFIX}/include

GNU_CONFIGURE=	YES
USE_GMAKE=	yes
MAKE_ENV+=	GCC=yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"

#eof
