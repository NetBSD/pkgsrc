# $NetBSD: Makefile,v 1.31 2025/01/28 00:47:03 schmonz Exp $

DISTNAME=		Text-Markdown-Discount-0.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Text-Markdown-Discount
COMMENT=		Convert Markdown to (X)HTML
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Markdown/Discount/.packlist

PERL5_MODULE_TYPE=	Module::Build

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	builder/MyBuilder.pm
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

# Avoid extracting the vendored discount library. We don't use it at all
# (instead buildlinking textproc/discount), and it sometimes contains
# macOS xattrs that break extraction as root on other systems.
EXTRACT_OPTS=		-X ${WRKDIR}/excludefile
pre-extract:
	${_EXTRACT_TAR} -ztf ${DISTDIR}/${DISTFILES} \
		| sort | grep /discount-2 > ${WRKDIR}/excludefile

.include "../../textproc/discount/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
