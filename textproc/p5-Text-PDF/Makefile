# $NetBSD: Makefile,v 1.5 2010/08/21 16:36:06 seb Exp $
#

DISTNAME=	Text-PDF-0.29a
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-PDF/
COMMENT=	Perl 5 module for manipulating PDF files

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Text-PDF-0.29
USE_LANGUAGES=	# empty

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

PERL5_PACKLIST=	auto/Text/PDF/.packlist

# Fix permissions after extraction
post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
