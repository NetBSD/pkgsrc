package intqa

// XXX: It might be nice to check all comments of the form "See XYZ"
// to see whether XYZ actually exists. The scope should be the current type,
// then the current package, then a package-qualified identifier.
// As if there were a "_ = XYZ" at the beginning of the function.

// XXX: If there is a constructor for a type, only that constructor may be used
// for constructing objects. All other forms (var x Type; x := &Type{}) should be forbidden.
