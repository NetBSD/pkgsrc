/* $NetBSD: netbsd.h,v 1.1.1.1 2006/07/10 17:35:30 drochner Exp $ */

#include <nsswitch.h>

enum nss_status {
        NSS_STATUS_SUCCESS,
	NSS_STATUS_NOTFOUND,
	NSS_STATUS_UNAVAIL,
	NSS_STATUS_TRYAGAIN,
	NSS_STATUS_RETURN
};
