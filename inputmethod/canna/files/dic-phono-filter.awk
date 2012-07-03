BEGIN {
	skip = 0
}

/^#ifdef SHIFT/ { skip = 0 }
/^#ifdef ASCII/ { skip = 1 }
/^#ifndef SHIFT/ { skip = 1 }
/^#ifndef ASCII/ { skip = 0 }
/^#else/ { skip = !skip }
/^#endif/ { skip = 0 }
/^#/ { next; }

{ if (!skip) print }
