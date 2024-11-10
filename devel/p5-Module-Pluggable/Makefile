# $NetBSD: Makefile,v 1.38 2024/11/10 17:39:40 pgoyette Exp $
#

EXTRACT_USING=  gtar	# XXX avoid extended attributes in distfile
			# https://rt.cpan.org/Ticket/Display.html?id=156825

DISTNAME=	Module-Pluggable-6.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Pluggable
COMMENT=	Automatically adds the ability to have plugins to modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Pluggable/.packlist

post-extract:
	 ${FIND} ${WRKSRC} -type f -name "*.pm" -print | ${XARGS} ${CHMOD} -x

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
