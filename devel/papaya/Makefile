# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 04:46:30 rh Exp $
#

DISTNAME=	papaya-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/		\
		${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/index.html
COMMENT=	Simple scripts for software development

USE_PERL5=	run
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

.include "../../textproc/texi2html/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
