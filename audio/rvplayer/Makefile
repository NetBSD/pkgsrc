# $NetBSD: Makefile,v 1.1.1.1 1999/08/29 01:32:27 jlam Exp $
#

DISTNAME=	rv50_linux20
PKGNAME=	rvplayer-5.0
WRKSRC=		${WRKDIR}/rvplayer5.0
CATEGORIES=	audio
MASTER_SITES=

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.real.com/products/player/

NO_CDROM=		"Redistribution not permitted"
RESTRICTED=		"Export-controlled"
MIRROR_DISTFILE=	no

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_CONFIGURE=		yes

.if !exists(/emul/linux/lib/ld-linux.so.1)
IGNORE=		requires Linux glibc2 libraries - see compat_linux(8)
.endif

REAL_HOME=	${PREFIX}/lib/rvplayer
DOCDIR=		${PREFIX}/share/doc/rvplayer

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  RealPlayer 5.0 for Linux-ELF must be fetched into"; \
	    ${ECHO_MSG} "  ${DISTDIR} from"; \
	    ${ECHO_MSG} "  http://www.real.com/products/player/downloadrealplayer.html."; \
	    ${ECHO_MSG} "==============================================================="; \
	fi

do-build:
	${SED} -e 's#@@REAL_HOME@@#${REAL_HOME}#g' \
	    <${FILESDIR}/rvplayer.sh >${WRKDIR}/rvplayer.sh

do-install:
	# Install RealPlayer and its codecs.
	#
	${INSTALL_DATA_DIR} ${REAL_HOME}
	${INSTALL_PROGRAM} ${WRKSRC}/rvplayer ${REAL_HOME}
.for file in libdecdnet.so libra14_4.so libra28_8.so libradnet.so \
    librarv10.so librasipr.so librv10dec.so librvcore.so rvplayer.ad
	${INSTALL_DATA} ${WRKSRC}/${file} ${REAL_HOME}
.endfor
	#
	# Install RealPlayer plug-ins.
	#
.for file in RAObserver.class RAPlayer.class librvplayer.so
	${INSTALL_DATA} ${WRKSRC}/${file} ${REAL_HOME}
.endfor
	#
	# Install the RealPlayer documentation.
	#
	${INSTALL_DATA_DIR} ${DOCDIR}
.for file in License.txt Mailcap Mime.types README welcome.rm
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/index.htm ${DOCDIR}
	${CP} -R ${WRKSRC}/doc ${DOCDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}
	${CHMOD} -R go-w ${DOCDIR}
	#
	# Install the RealPlayer wrapper script.
	#
	${INSTALL_SCRIPT} ${WRKDIR}/rvplayer.sh ${PREFIX}/bin/rvplayer

.include "../../mk/bsd.pkg.mk"
