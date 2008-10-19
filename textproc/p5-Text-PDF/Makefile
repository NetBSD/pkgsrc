# $NetBSD: Makefile,v 1.3 2008/10/19 19:18:56 he Exp $
#

DISTNAME=	Text-PDF-0.29a
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-PDF/
COMMENT=	Perl 5 module for manipulating PDF files

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Text-PDF-0.29
USE_LANGUAGES=	# empty

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=	auto/Text/PDF/.packlist

# Fix permissions after extraction
post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
