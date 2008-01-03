# $NetBSD: Makefile,v 1.59 2008/01/03 23:21:41 heinz Exp $
#

DISTNAME=	tcsh-6.15.00
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.gw.com/pub/unix/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.tcsh.org/Welcome
COMMENT=	Extended C-shell with many useful features

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS?=	static-tcsh-[0-9]*

GNU_CONFIGURE=	yes
BUILD_TARGET=	all catalogs
INSTALL_TARGET=	install install.man

NLSDIR=		share/nls
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
OS_VER_cmd=	${ECHO} ${OS_VERSION} | ${SED} -e 's|5\.|2.|'
LOWER_OPSYS=	solaris${OS_VER_cmd:sh}
.endif

PKG_SHELL?=	bin/tcsh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	@${ECHO} "Installing message catalogues"
	cp ${PKGDIR:Q}/PLIST ${PLIST_SRC:Q}
	set -e;							\
	if [ -f ${WRKSRC:Q}/tcsh.C.cat ];				\
	then								\
	    [ -d ${DESTDIR}${PREFIX:Q}/${NLSDIR:Q}/C ] ||		\
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/${NLSDIR:Q}/C;\
	    ${INSTALL_DATA} ${WRKSRC:Q}/tcsh.C.cat 			\
		${DESTDIR}${PREFIX}/${NLSDIR:Q}/C/tcsh.cat;		\
	    ${ECHO} ${NLSDIR:Q}/C/tcsh.cat >> ${PLIST_SRC:Q};		\
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
		    d=${NLSDIR:Q}/$${c}_$$1.$${s};			\
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

.include "../../mk/bsd.pkg.mk"
