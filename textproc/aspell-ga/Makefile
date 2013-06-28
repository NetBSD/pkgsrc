# $NetBSD: Makefile,v 1.3 2013/06/28 08:35:30 rodent Exp $

DISTNAME=	aspell5-ga-4.6-0
PKGNAME=	${DISTNAME:S/5-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	http://gaelspell.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-gaeilge-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
