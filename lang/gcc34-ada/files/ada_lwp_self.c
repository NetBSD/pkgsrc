/* Binding to _lwp_self for the Ada RTS */
#include <lwp.h>

lwpid_t ada_lwp_self(void) {
    return _lwp_self();
}
