# $NetBSD: Makefile,v 1.6 2003/10/28 23:22:54 kristerw Exp $
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
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/misc/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/misc/config.sub
INFO_FILES=	papaya.info

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

.include "../../textproc/texi2html/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
