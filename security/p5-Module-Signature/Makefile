# $NetBSD: Makefile,v 1.49 2025/04/27 05:59:36 wiz Exp $

DISTNAME=	Module-Signature-0.89
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Signature
COMMENT=	Perl 5 module for module signature file manipulation
LICENSE=	public-domain

DEPENDS+=		p5-Crypt-OpenPGP>=1.00:../../security/p5-Crypt-OpenPGP
TEST_DEPENDS+=		p5-IPC-Run>=0:../../devel/p5-IPC-Run

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Signature/.packlist

INSTALLATION_DIRS+=	share/Module-Signature

PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_ENV+=		TEST_SIGNATURE=1
# one self test failure in 0.89:
# https://github.com/audreyt/module-signature/issues/23

# this package has patch files so the signature check test fails
#post-extract:
#	${MV} ${WRKSRC}/t/0-signature.t ${WRKSRC}/t/0-signature.t.SKIP

post-install:
	${RUN} for f in ${WRKSRC}/*.pub; do ${INSTALL_DATA} "$$f"	\
		${DESTDIR}${PREFIX}/share/Module-Signature;		\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
