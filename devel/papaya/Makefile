# $NetBSD: Makefile,v 1.4 2003/07/17 21:32:59 grant Exp $
#

DISTNAME=	papaya-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/		\
		${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/index.html
COMMENT=	Simple scripts for software development

USE_PERL5=	run
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	papaya.info

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

.include "../../textproc/texi2html/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
