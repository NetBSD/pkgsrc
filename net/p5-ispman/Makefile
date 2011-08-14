# $NetBSD: Makefile,v 1.24 2011/08/14 14:14:50 obache Exp $
#

DISTNAME=		ispman-0.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
SVR4_PKGNAME=		p5isp
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ispman/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ispman.org/
COMMENT=		Perl module for ISPMan webAdministrator and command line utils

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{p5-CGI>=2.72,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Text-Template>=1.23:../../textproc/p5-Text-Template
DEPENDS+=		p5-perl-ldap>=0.22:../../databases/p5-perl-ldap
DEPENDS+=		p5-IMAP-Admin>=1.2.5:../../mail/p5-IMAP-Admin
DEPENDS+=		p5-Convert-ASN1>=0.07:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-IO-stringy>=1.213:../../devel/p5-IO-stringy

WRKSRC=			${WRKDIR}/ispman/Modules
PERL5_PACKLIST=		auto/ISPMan/.packlist
PERL5_CONFIGURE_DIRS=	${WRKSRC}/ISPMan ${WRKSRC}/IO-stringy-1.212_patched
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}
INSTALL_DIRS=		${WRKSRC}/ISPMan
INSTALLATION_DIRS=	${PERL5_INSTALLVENDORLIB}/IO

MAKE_PARAMS+=		--noprompt

SUBST_CLASSES+=		etc-fix
SUBST_STAGE.etc-fix=	pre-configure
SUBST_FILES.etc-fix=	ISPMan/*
SUBST_SED.etc-fix=	-e 's:/etc:${PREFIX}/etc:g'

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA} ${WRKSRC}/IO-stringy-1.212_patched/lib/IO/Scalar.pm \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/IO/ScalarPatched.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
