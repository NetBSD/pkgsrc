# $NetBSD: Makefile,v 1.3 2005/02/19 10:35:00 wiz Exp $
#

DISTNAME=	Module-Signature-0.44
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ms
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Signature/
COMMENT=	Perl 5 module adding cryptographic authentications to CPAN distributions

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-PAR-Dist-[0-9]*:../../devel/p5-PAR-Dist

USE_BUILDLINK3=	YES
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Module/Signature/.packlist

INSTALLATION_DIRS+=	share/Module-Signature

# this package has patch files so the signature check test fails
post-extract:
	${MV} ${WRKSRC}/t/0-signature.t ${WRKSRC}/t/0-signature.t.SKIP

post-install:
	${PKG_SILENT}${PKG_DEBUG}	\
	for f in ${WRKSRC}/*.pub; do	\
		${INSTALL_DATA} $$f ${PREFIX}/share/Module-Signature;	\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
