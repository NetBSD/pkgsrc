# $NetBSD: Makefile,v 1.5 2001/05/22 10:58:30 wiz Exp $
#

DISTNAME=	icecast-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

DEPENDS+=	unproven-pthreads>=0.17:../../devel/unproven-pthreads
DEPENDS+=	readline-4.*:../../devel/readline

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
