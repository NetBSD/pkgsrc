# $NetBSD: Makefile,v 1.20 2017/06/05 14:23:52 ryoon Exp $

DISTNAME=	autodie-2.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autodie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autodie/
COMMENT=	Replace functions with ones that succeed or die with lexical scope
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IPC-System-Simple>=0.12:../../devel/p5-IPC-System-Simple
DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

PERL5_PACKLIST=		auto/autodie/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
