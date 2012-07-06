# $NetBSD: Makefile,v 1.7 2012/07/06 13:47:44 sno Exp $

DISTNAME=	autodie-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autodie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autodie/
COMMENT=	Replace functions with ones that succeed or die with lexical scope
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IPC-System-Simple>=0.12:../../devel/p5-IPC-System-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/autodie/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
