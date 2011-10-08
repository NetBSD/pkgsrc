# $NetBSD: Makefile,v 1.6 2011/10/08 03:40:41 hiramatsu Exp $

DISTNAME=	Template-Tiny-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Tiny/
COMMENT=	Template Toolkit reimplemented in as little code as possible
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Capture-Tiny>=0.07:../../devel/p5-Capture-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Template/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
