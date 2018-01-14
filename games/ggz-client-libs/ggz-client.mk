# $NetBSD: ggz-client.mk,v 1.2 2018/01/14 17:33:59 rillig Exp $

REALGGZCONFIG=	${PREFIX}/bin/ggz-config

CONFIGURE_ARGS+=	--with-ggzconfig=${WRAPPER_DIR}/bin

pre-configure: ${WRAPPER_DIR}/bin/ggz-config

${WRAPPER_DIR}/bin/ggz-config:
	${PRINTF} "#! ${SH}\\n\
	  case \$$1 in\\n\
	  --configdir|--gamedir|--datadir) ${REALGGZCONFIG} \$$1;;\\n\
	  *) exit 0;;\\n\
	  esac\\n\
	" > ${.TARGET}
	${CHMOD} +x ${.TARGET}
