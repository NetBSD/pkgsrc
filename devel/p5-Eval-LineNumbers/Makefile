# $NetBSD: Makefile,v 1.9 2024/11/16 12:04:09 wiz Exp $

# no Release yet
GIT_COMMIT=	d1d7556
DISTNAME=	master
PKGNAME=	p5-Eval-LineNumbers-0.1
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=/muir/Eval-LineNumbers/archive/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	Eval-LineNumbers-${GIT_COMMIT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/muir/Eval-LineNumbers
COMMENT=	Add line numbers to heredoc blocks that contain perl source code
LICENSE=	${PERL5_LICENSE}

WRKSRC=		${WRKDIR}/Eval-LineNumbers-${DISTNAME}

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl
PERL5_PACKLIST=	auto/Eval/LineNumbers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
