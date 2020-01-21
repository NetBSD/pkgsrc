# $NetBSD: Makefile,v 1.20 2020/01/21 10:28:50 schmonz Exp $
#

DISTNAME=		Text-Markdown-Discount-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-Markdown-Discount
COMMENT=		Convert Markdown to (X)HTML
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Markdown/Discount/.packlist

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile.PL
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

post-extract:
	cd ${WRKSRC} && rm -rf discount

.include "../../textproc/discount/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
