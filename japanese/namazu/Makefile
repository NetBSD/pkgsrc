# $NetBSD: Makefile,v 1.4 1999/09/30 05:51:08 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/03/31 11:52:07 flathill Exp $

DISTNAME=	namazu-1.3.0.10
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/namazu/release/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/namazu/

DEPENDS=	kakasi-2.2.5:../../japanese/kakasi \
		nkf-1.7:../../japanese/nkf

USE_PERL5=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
