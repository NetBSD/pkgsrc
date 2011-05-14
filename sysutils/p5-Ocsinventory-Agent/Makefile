# $NetBSD: Makefile,v 1.1.1.1 2011/05/14 23:10:48 abs Exp $
#

DISTNAME=	Ocsinventory-Agent-1.1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GO/GONERI/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Ocsinventory-Agent/
COMMENT=	Unified client for OCS-Inventory
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Net-IP>=1.21:../../net/p5-Net-IP
DEPENDS+=	p5-Proc-Daemon-[0-9]*:../../devel/p5-Proc-Daemon
DEPENDS+=	p5-Proc-PID-File-[0-9]*:../../devel/p5-Proc-PID-File
DEPENDS+=	p5-XML-Simple>=2.12:../../textproc/p5-XML-Simple
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+= lib/Ocsinventory/Agent.pm postinst.pl

post-configure:
	${RM} ${WRKSRC}/run-postinst

PERL5_PACKLIST=		auto/Ocsinventory/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
