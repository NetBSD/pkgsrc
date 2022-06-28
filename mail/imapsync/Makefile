# $NetBSD: Makefile,v 1.26 2022/06/28 11:34:21 wiz Exp $

DISTNAME=	imapsync-2.140
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=imapsync/}
GITHUB_TAG=	refs/tags/${DISTNAME}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/imapsync/imapsync/
COMMENT=	Incremental recursive IMAP transfer tool
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/imapsync-${DISTNAME}
USE_LANGUAGES=	# none

DEPENDS+=	p5-Crypt-OpenSSL-RSA-[0-9]*:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=	p5-Dist-CheckConflicts-[0-9]*:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Encode-IMAPUTF7-[0-9]*:../../textproc/p5-Encode-IMAPUTF7
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-Tee-[0-9]*:../../devel/p5-IO-Tee
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Mail-IMAPClient-[0-9]*:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation
DEPENDS+=	p5-Module-ScanDeps-[0-9]*:../../devel/p5-Module-ScanDeps
DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
DEPENDS+=	p5-Package-Stash-XS-[0-9]*:../../devel/p5-Package-Stash-XS
DEPENDS+=	p5-PAR-Packer-[0-9]*:../../devel/p5-PAR-Packer
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Sys-MemInfo-[0-9]*:../../sysutils/p5-Sys-MemInfo
DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
DEPENDS+=	p5-Test-Mock-Guard-[0-9]*:../../devel/p5-Test-Mock-Guard
DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
DEPENDS+=	p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL+=	imapsync

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapsync ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/imapsync

.include "../../mk/bsd.pkg.mk"
