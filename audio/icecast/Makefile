# $NetBSD: Makefile,v 1.2 2000/12/28 16:49:37 wiz Exp $
#

DISTNAME=	icecast-1.3.7
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.icecast.org/

DEPENDS+=	unproven-pthreads>=0.17:../../devel/unproven-pthreads
DEPENDS+=	readline-4.*:../../devel/readline

# Sync these with devel/unproven-pthreads
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-readline \
		--with-libwrap \
		--with-python \
		--with-python-includes=${LOCALBASE}/include \
		--with-python-libraries=${LOCALBASE}/lib
R=		${LOCALBASE}/include/readline
P=		${LOCALBASE}/pthreads
CONFIGURE_ENV+=	 CC='$P/bin/pgcc -I$P/include -I$R -L$P/lib' \
		CXX='$P/bin/pg++ -I$P/include -I$R -L$P/lib'

.include "../../mk/bsd.pkg.mk"
