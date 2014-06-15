/*
 *	$NetBSD: sm_os_netbsd.h,v 1.1 2014/06/15 20:48:49 jnemeth Exp $
 */

/*
**  Platform definitions for NetBSD
*/

#define SM_OS_NAME	"netbsd"

#define SM_CONF_SYS_CDEFS_H	1

#include <sys/param.h> /* defines __NetBSD_version__ */
#if __NetBSD_version__ >= 104000300
   /* 1.4.3 and later have strlcpy()/strlcat() */
#  ifndef SM_CONF_STRL
#     define SM_CONF_STRL		1
#  endif
#endif

#ifndef SM_CONF_SHM
# define SM_CONF_SHM	1
#endif /* SM_CONF_SHM */
#ifndef SM_CONF_SEM
# define SM_CONF_SEM	0
#endif /* SM_CONF_SEM */
#ifndef SM_CONF_MSG
# define SM_CONF_MSG	1
#endif /* SM_CONF_MSG */
