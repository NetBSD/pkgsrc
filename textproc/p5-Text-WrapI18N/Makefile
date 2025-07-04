# $NetBSD: Makefile,v 1.26 2025/07/04 08:48:34 wiz Exp $

DISTNAME=	Text-WrapI18N-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-WrapI18N
COMMENT=	Perl5 module to wrap internationalized text

DEPENDS+=	p5-Text-CharWidth-[0-9]*:../../textproc/p5-Text-CharWidth

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/WrapI18N/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
