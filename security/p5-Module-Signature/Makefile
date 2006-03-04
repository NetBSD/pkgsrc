# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:37 jlam Exp $
#

DISTNAME=	Module-Signature-0.44
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ms
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Signature/
COMMENT=	Perl5 module adding cryptographic authentications to CPAN distributions

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-PAR-Dist-[0-9]*:../../devel/p5-PAR-Dist

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Signature/.packlist

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
