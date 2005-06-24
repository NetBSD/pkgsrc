# $NetBSD: Makefile,v 1.19 2005/06/24 06:43:43 jlam Exp $
#

DISTNAME=		MLDBM-2.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mld
PKGREVISION=		1
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html
COMMENT=		Perl5 module for storing arbitrary data in tied hashes

DEPENDS+= 		{p5-Data-Dumper>=2.08,perl{,-thread}>=5.6.1nb2}:../../lang/perl5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MLDBM/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
