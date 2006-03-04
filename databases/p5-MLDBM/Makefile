# $NetBSD: Makefile,v 1.22 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=		MLDBM-2.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mld
PKGREVISION=		2
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html
COMMENT=		Perl5 module for storing arbitrary data in tied hashes

DEPENDS+= 		{p5-Data-Dumper>=2.08,perl{,-thread}>=5.6.1nb2}:../../lang/perl5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MLDBM/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
