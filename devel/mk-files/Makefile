# $NetBSD: Makefile,v 1.4 2002/02/06 16:58:13 jlam Exp $
#

DISTNAME=       mk-1.2.5
PKGNAME=	mk-files-1.2.5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.netbsd.org/pub/incoming/sjg/

MAINTAINER=	sjg@netbsd.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	portable *.mk files for the NetBSD portable bmake utility

WRKSRC=		${WRKDIR}/mk

NO_CONFIGURE=	yes
NO_BUILD=	yes

MKFILES=	autodep.mk dep.mk doc.mk lib.mk man.mk nls.mk 
MKFILES+=	obj.mk own.mk prog.mk subdir.mk target-flags.mk

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
# we don't want to use these on BSD systems, since prog.mk and
# lib.mk now rely on finding the correct bsd.prog.mk etc to
# get the right magic on ELF systems.
MKFILES+=	bsd.dep.mk bsd.doc.mk bsd.lib.mk bsd.man.mk
MKFILES+=	bsd.nls.mk bsd.obj.mk bsd.own.mk bsd.prog.mk bsd.subdir.mk

# need to include the commented out guys
PLIST_SRC=${WRKDIR}/.PLIST_SRC

${WRKDIR}/.PLIST_SRC:	${PKGDIR}/PLIST
	@${SED} 's,^@comment.*skip-on-BSD ,,' $> > $@

.endif

do-install:
.if ${OPSYS} != "NetBSD"
	${INSTALL_DATA} ${WRKSRC}/`uname -s`.sys.mk ${PREFIX}/share/mk/sys.mk
.endif
	for f in ${MKFILES}; do						\
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/mk/;	\
	done

.include "../../mk/bsd.pkg.mk"

