# $NetBSD: Makefile,v 1.17 2024/06/27 17:40:34 abs Exp $
#

DISTNAME=	dirvish-1.2.1
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	https://dirvish.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dirvish.org/
COMMENT=	Fast, disk based, rotating network backup system
#LICENSE=	osl-2.0

DEPENDS+=	rsync>=2.6.0:../../net/rsync
#DEPENDS+=	{perl>=5.8.8,p5-Getopt-Long>=2.35}:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Time-modules>=2003.0:../../time/p5-Time-modules
DEPENDS+=	p5-Time-Period>=1.0:../../time/p5-Time-Period

PKG_SYSCONFSUBDIR=	dirvish
DIST_SUBDIR=		dirvish-20120107

EXECUTABLES=	dirvish dirvish-runall dirvish-expire dirvish-locate
MAN5=		dirvish.conf.5
MAN8=		dirvish.8 dirvish-runall.8 dirvish-expire.8 \
		dirvish-locate.8
DOCS=		COPYING FAQ.html INSTALL RELEASE.html TODO.html

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin \
			share/doc/dirvish

do-build:
	set -e; \
        cd ${WRKSRC}; \
	for f in ${EXECUTABLES}; do \
		${ECHO} "#!${PERL5}" > $$f; \
		${ECHO} "\$$CONFDIR = \"${PKG_SYSCONFDIR}\";" >> $$f; \
		${CAT} $$f.pl >>$$f; \
		${CAT} loadconfig.pl >>$$f; \
	done

do-install:
	for f in ${EXECUTABLES}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/sbin; \
	done
	for f in ${MAN5}; do \
		${INSTALL_MAN} ${WRKSRC}/$$f \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man5; \
	done
	for f in ${MAN8}; do \
		${INSTALL_MAN} ${WRKSRC}/$$f \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	done
	for f in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${DESTDIR}${PREFIX}/share/doc/dirvish; \
	done

.include "../../mk/bsd.pkg.mk"
