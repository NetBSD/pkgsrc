# $NetBSD: openwin.mk,v 1.2 2004/11/11 17:44:39 sketch Exp $

FILES_LIST=	${FILESDIR}/openwin

# Fix bugs in older versions of openwin headers
STDC_REPLACE=	-e 's/^\#if (__STDC__/\#if (defined(__STDC__)/'
STDC_REPLACE+=	-e 's/^\#if ((__STDC__/\#if ((defined(__STDC__)/'

CREATE_X11LINK=	case $$file in						\
		include/X11/Xlibint.h)					\
			${SED} ${STDC_REPLACE} < $$src > $$dest;	\
			;;						\
		include/X11/Xmd.h)					\
			${SED} ${STDC_REPLACE} < $$src > $$dest;	\
			;;						\
		include/X11/extensions/multibufst.h)			\
			${SED} ${STDC_REPLACE} < $$src > $$dest;	\
			;;						\
		*)							\
			${LN} -s $$src $$dest;				\
		esac
