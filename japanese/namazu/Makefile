# $NetBSD: Makefile,v 1.2 1999/06/08 10:40:23 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/03/31 11:52:07 flathill Exp $

DISTNAME=	namazu-1.3.0.7
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/namazu/release/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/namazu/

DEPENDS=	kakasi-2.2.5:../../japanese/kakasi \
		nkf-1.7:../../japanese/nkf

USE_PERL5=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/namazu-1.3.0.7/src

.include "../../mk/bsd.pkg.mk"
