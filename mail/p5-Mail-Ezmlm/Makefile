# $NetBSD: Makefile,v 1.25 2022/06/28 11:34:28 wiz Exp $
#

DISTNAME=		Ezmlm-0.08.2
PKGNAME=		p5-Mail-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Ezmlm
COMMENT=		Perl5 module for managing ezmlm mailing lists

DEPENDS+=		qmail>=1.03:../../mail/qmail
DEPENDS+=		{ezmlm>=0.53,ezmlm-idx>=0.40}:../../mail/ezmlm

MAKE_ENV+=		BSD_BATCH_INSTALL=1	# skip interactive config stage

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Ezmlm.pm
SUBST_VARS.paths=	LOCALBASE
SUBST_VARS.paths+=	QMAILDIR
SUBST_MESSAGE.paths=	Configuring paths.

PERL5_PACKLIST=		auto/Mail/Ezmlm/.packlist

BUILD_DEFS+=		QMAILDIR

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
