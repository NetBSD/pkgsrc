# $NetBSD: Makefile,v 1.12 2004/02/18 00:06:07 heinz Exp $
#

DISTNAME=		MLDBM-2.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mld
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html
COMMENT=		Perl5 module for storing arbitrary data in tied hashes

DEPENDS+= 		{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:${PERL5_PKGSRCDIR}

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MLDBM/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
