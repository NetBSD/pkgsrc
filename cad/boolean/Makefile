# $NetBSD: Makefile,v 1.1.1.1 2000/11/18 17:57:27 dmcmahill Exp $
#

DISTNAME=	boolean
PKGNAME=	boolean-${REL}
CATEGORIES=	cad graphics
MASTER_SITES=	http://www.xs4all.nl/~kholwerd/download/boolzip/
EXTRACT_SUFX=	.zip

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~kholwerd/bool.html

DEPENDS+=	wxGTK>=2.2.1:../../x11/wxGTK

DIST_SUBDIR=	${PKGNAME}
REL=		6.2

WRKSRC=		${WRKDIR}/boolean/${REL}/linux
MAKEFILE=	makefile.gui
PLIST_SUBST=	REL=${REL}

post-patch:
	${MV} ${WRKSRC}/../../toolmanager ${WRKSRC}/../../toolmanager.in
	${SED} "s;@prefix@;${PREFIX};g" < ${WRKSRC}/../../toolmanager.in \
	  > ${WRKSRC}/../../toolmanager

do-install:
	${INSTALL_DATA_DIR}  ${PREFIX}/libexec/boolean/${REL}/${LOWER_OPSYS}/bin
	${INSTALL_DATA_DIR}  ${PREFIX}/libexec/boolean/${REL}/all_arch.all_os/bin/
	cd ${WRKSRC}/.. && \
		tar cf - default gdsuser | tar -xvf - -C ${PREFIX}/libexec/boolean/${REL}
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/libexec/boolean/${REL}
	${INSTALL_SCRIPT} ${WRKSRC}/../../toolmanager ${PREFIX}/libexec/boolean/toolmanager
	${INSTALL_SCRIPT} ${WRKSRC}/../release_settings.sh ${PREFIX}/libexec/boolean/${REL}/release_settings.sh
	${INSTALL_SCRIPT} ${WRKSRC}/../all_arch.all_os/bin/*  ${PREFIX}/libexec/boolean/${REL}/all_arch.all_os/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/boolean_exe  ${PREFIX}/libexec/boolean/${REL}/${LOWER_OPSYS}/bin/
	cd ${PREFIX}/bin ; \
	for f in  boolean booleanc booleanterm booleantest boolean_man ; \
	do \
		${LN} -f -s ../libexec/boolean/toolmanager $$f ;\
	done
	cd ${PREFIX}/libexec/boolean/ && ${LN} -f -s ${REL} default

.include "../../mk/bsd.pkg.mk"
