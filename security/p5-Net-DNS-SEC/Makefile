# $NetBSD: Makefile,v 1.5 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=		Net-DNS-SEC-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5nds
CATEGORIES=		security net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.ripe.net/disi/
COMMENT=		DNSSEC extension to Net::DNS Perl DNS Resolver Module

DEPENDS+=		p5-Net-DNS>=0.40:../../net/p5-Net-DNS
DEPENDS+=		p5-Crypt-OpenSSL-RSA>=0.19:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=		p5-Crypt-OpenSSL-Bignum>=0.03:../../security/p5-Crypt-OpenSSL-Bignum
DEPENDS+=		p5-Crypt-OpenSSL-DSA>=0.10:../../security/p5-Crypt-OpenSSL-DSA
DEPENDS+=		p5-Digest-SHA1>=2.04:../../security/p5-Digest-SHA1
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Digest-BubbleBabble>=0.01:../../security/p5-Digest-BubbleBabble

BUILDLINK_DEPENDS.perl=	perl>=5.6.1
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/SEC/.packlist

REPLACE_PERL=		demo/getkeyset.pl demo/key2ds demo/make-signed-keyset

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

OWN_DIRS+=		${DOCDIR} ${EGDIR}

SUBST_CLASSES+=		p5nds
SUBST_STAGE.p5nds=	post-install
SUBST_FILES.p5nds=	demo/getkeyset.pl
SUBST_SED.p5nds=	-e "1s,-I./blib/lib,,"

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README  ${DOCDIR}/
.for f in getkeyset.pl key2ds make-signed-keyset
	@${INSTALL_SCRIPT} ${WRKSRC}/demo/${f} ${EGDIR}/
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
