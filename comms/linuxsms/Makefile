# $NetBSD: Makefile,v 1.5 2003/09/02 12:48:33 seb Exp $
#

DISTNAME=	linuxsms-0.65
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxsms/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linuxsms.sourceforge.net/
COMMENT=	Perl script to send short messages to GSM phones

USE_BUILDLINK2=	yes
USE_PERL5=	yes
NO_BUILD=	yes

REPLACE_PERL=	linuxsms

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linuxsms ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linuxsms.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/linuxsms
.for f in BUGS CHANGES README README.ES TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/linuxsms
.endfor
.undef f

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
