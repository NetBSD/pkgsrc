# $NetBSD: Makefile,v 1.5 1999/05/29 17:57:52 sakamoto Exp $

DISTNAME=	xps-3.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netwinder.org/users/r/rocky/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netwinder.org/~rocky/xps-home/

BUILD_DEPENDS=	${LOCALBASE}/bin/perl:${PKGSRCDIR}/lang/perl5

USE_GMAKE=	yes
USE_X11BASE=	yes
USE_MOTIF=	yes

GNU_CONFIGURE=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
