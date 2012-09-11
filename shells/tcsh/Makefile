# $NetBSD: Makefile,v 1.72 2012/09/11 23:25:09 asau Exp $

DISTNAME=	tcsh-6.18.01
PKGREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.tcsh.org/Welcome
COMMENT=	Extended C-shell with many useful features
LICENSE=	original-bsd

CONFLICTS?=	static-tcsh-[0-9]*

GNU_CONFIGURE=	yes
BUILD_TARGET=	all catalogs
INSTALL_TARGET=	install install.man

NLSDIR=		share/nls
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS_VERSUFFIX=	${OS_VERSION:S/5./2./}
.endif

PKG_SHELL?=	bin/tcsh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	@${ECHO} "Installing message catalogues"
	cp ${PKGDIR}/PLIST ${PLIST_SRC}
	set -e;							\
	if [ -f ${WRKSRC}/tcsh.C.cat ];				\
	then							\
	    [ -d ${DESTDIR}${PREFIX}/${NLSDIR}/C ] ||		\
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${NLSDIR}/C;	\
	    ${INSTALL_DATA} ${WRKSRC}/tcsh.C.cat 			\
		${DESTDIR}${PREFIX}/${NLSDIR}/C/tcsh.cat;		\
	    ${ECHO} ${NLSDIR}/C/tcsh.cat >> ${PLIST_SRC};		\
	    for i in 							\
		et:ISO_8859-15:et:EE					\
		finnish:ISO_8859-1:fi:FI				\
		french:ISO_8859-1:fr:BE:CA:CH:FR			\
		german:ISO_8859-1:de:AT:CH:DE				\
		greek:ISO_8859-7:el:GR					\
		italian:ISO_8859-1:it:CH:IT				\
		ja:eucJP:ja:JP						\
		pl:ISO_8859-2:pl:PL					\
		russian:KOI8-R:ru:RU:SU					\
		spanish:ISO_8859-1:es:ES				\
		ukrainian:KOI8-U:uk:UA					\
		;							\
	    do								\
		OIFS="$${IFS}";						\
		IFS=":$${IFS}";						\
		set -- $$i;						\
		IFS="$${OIFS}";						\
		l=$$1; shift;						\
		s=$$1; shift;						\
		c=$$1; shift;						\
		o=;							\
		while [ $$# -gt 0 ];					\
		do							\
		    d=${NLSDIR}/$${c}_$$1.$${s};			\
		    [ -d ${DESTDIR}${PREFIX}/$$d ] ||			\
			${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/$$d;	\
		    if [ -z "$$o" ];					\
		    then						\
			o="$$d";					\
			${INSTALL_DATA} ${WRKSRC}/tcsh.$${l}.cat	\
			    ${DESTDIR}${PREFIX}/$${d}/tcsh.cat;		\
		    else						\
			${LN} -f ${DESTDIR}${PREFIX}/$${o}/tcsh.cat	\
			    ${DESTDIR}${PREFIX}/$${d};			\
		    fi;							\
		    ${ECHO} $${d}/tcsh.cat >> ${PLIST_SRC};		\
		    shift 1;						\
		done;							\
	    done;							\
	fi

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
