# $NetBSD: Makefile,v 1.4 2013/06/28 08:57:27 rodent Exp $
#

DISTNAME=	ispell-sk-0.3.2
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/files/
MASTER_SITES+=	http://www.sk-spell.sk.cx/file_download/19/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.sk-spell.sk.cx/ispell-sk
COMMENT=	Slovak dictionary for ispell
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

CONFLICTS+=	ispell-slovak-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

.include "../../mk/bsd.pkg.mk"
