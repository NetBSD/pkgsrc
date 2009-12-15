# $NetBSD: Makefile,v 1.15 2009/12/15 13:28:13 wiz Exp $
#

DISTNAME=	Module-Signature-0.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ms
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Signature/
COMMENT=	Perl5 module adding cryptographic authentications to CPAN distributions
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Signature/.packlist

INSTALLATION_DIRS+=	share/Module-Signature

#PERL5_MODULE_TYPE=	Module::Install
MAKE_PARAMS+=		--skipdeps

# this package has patch files so the signature check test fails
post-extract:
	${MV} ${WRKSRC}/t/0-signature.t ${WRKSRC}/t/0-signature.t.SKIP

post-install:
	${PKG_SILENT}${PKG_DEBUG}	\
	for f in ${WRKSRC}/*.pub; do ${INSTALL_DATA} $$f	\
		${DESTDIR:Q}${PREFIX:Q}/share/Module-Signature;	\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
