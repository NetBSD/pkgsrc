# $NetBSD: Makefile,v 1.14 2008/03/03 05:33:32 jlam Exp $
#

DISTNAME=	linuxsms-0.65
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxsms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxsms.sourceforge.net/
COMMENT=	Perl script to send short messages to GSM phones

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
NO_BUILD=	yes

REPLACE_PERL=	linuxsms

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linuxsms ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linuxsms.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/linuxsms
.for f in BUGS CHANGES README README.ES TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/linuxsms
.endfor

.include "../../mk/bsd.pkg.mk"
