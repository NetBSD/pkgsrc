# $NetBSD: Makefile,v 1.15 2002/09/21 06:49:25 jlam Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz
DISTFILES=	pcb-1.6.3.tgz \
		pcb-docs-1.6.3.tar.gz

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~haceaton/pcb/
COMMENT=	X11 interactive printed circuit board layout system

DEPENDS+=	m4-1.4:../../devel/m4

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

PKG_SYSCONFSUBDIR=	pcb
DOCDIR=			${PREFIX}/share/doc/pcb
EGDIR=			${PREFIX}/share/examples/pcb
INFODIR=		${PREFIX}/info
M4DIR=			${PREFIX}/lib/x11/pcb/m4

INFO_FILES=	pcb.info
CONF_FILES=	${EGDIR}/local.inc ${PKG_SYSCONFDIR}/local.inc

# avoid picking up any user config files during the build
MAKE_ENV+=	HOME=${WRKSRC}

post-patch:
	for file in ${WRKSRC}/config.h; do				\
		${SED}	-e "s|@sysconfdir@|${PKG_SYSCONFDIR}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcb.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcb.info ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcb.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/refcard.ps ${DOCDIR}
	for file in ${M4DIR}/common.m4; do				\
		${AWK} '						\
		/^divert\(0\)dnl/ {					\
			printf("include(${PKG_SYSCONFDIR}/local.inc)\n"); \
			printf("sinclude(site-config.inc)\n");		\
			printf("sinclude(user-config.inc)\n");		\
			printf("sinclude(proj-config.inc)\n");		\
		}							\
		{
			gsub(/^include\(/,"include(${M4DIR}/");		\
			print;						\
		}'							\
		$${file} > $${file}.fixed;				\
		${MV} -f $${file}.fixed $${file};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${ECHO} "# list your local includes here" > ${EGDIR}/local.inc

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
