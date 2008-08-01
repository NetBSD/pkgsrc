# $NetBSD: Makefile,v 1.5 2008/08/01 21:01:26 schmonz Exp $
#

DISTNAME=		Ezmlm-0.07.2
PKGNAME=		p5-Mail-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~sumpfrall/Ezmlm/
COMMENT=		Perl5 module for managing ezmlm mailing lists

DEPENDS+=		qmail>=1.03:../../mail/qmail
DEPENDS+=		{ezmlm>=0.53,ezmlm-idx>=0.40}:../../mail/ezmlm

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		BSD_BATCH_INSTALL=1	# skip interactive config stage

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Ezmlm.pm
SUBST_SED.paths=	-e 's|@LOCALBASE@|${LOCALBASE}|g'
SUBST_SED.paths+=	-e 's|@QMAILDIR@|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	Configuring paths.

PERL5_PACKLIST=		auto/Mail/Ezmlm/.packlist

BUILD_DEFS+=		QMAILDIR

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
